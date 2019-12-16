# [datagrok](https://github.com/datagrok)'s layout for the Mitosis

- Emphasis on momentary modifiers, all usable from either hand, arranged symmetrically, but left/right distinguishable by the OS.
  I place left- and right-versions of Shift, GUI ("Super"), and Alt ("Meta"), and Henkan/Muhenkan (which I plan to overload for "Hyper").

  I'm going for a [Space Cadet](https://en.wikipedia.org/wiki/Space-cadet_keyboard) aesthetic;
  I want a keyboard that can (even just in theory) make use of all the bucky bits my operating system can support.

- Red key and Blue key momentary-enable (like a shift key) one of three layers:

    - Red: common symbols and arrow keys
    - Blue: numbers arranged in a 10-key pad and function keys
    - Purple ("Red and Blue"): "true number-pad", page up/page down/home/end, and uncommon functions
    
  This tri-state layer mechanism is a bit similar to Planck and Preonic's "Raise," "Lower," and "Adjust."

- The base layer is QWERTY.
  [Colemak][], [Dvorak][], and [Workman][] may be toggled using `Red`+`Blue`+`Z`.
  When you find the one you like, save it with `Shift`+`Red`+`Blue`+`Z`.

- Minimize hand travel, so as not to lose orientation with home row.

- `?` and `!` are moved to take the place of `<` and `>`.
  Rationale: unmodded and shifted keys should be for prose, while symbols useful for programming should be colocated on their own layer.

- Key positions chosen for mnemonics.
  For example, you can distinguish between alphanumeric numerals and number-pad numerals, but they occupy the same key positions.

## Layers

### Base

![mitosis:datagrok layout base layer](https://i.imgur.com/tap5Pjf.png)

- customized comma and period, which have exclamation point and question mark on their shift layer.
- tap right-shift for underscore, tap left-shift for tab.

### Red

Intended for common navigation and programming symbols.

![mitosis:datagrok layout red layer](https://i.imgur.com/sMGr34T.png)

- symmetric layout of paired braces/brackets/slashes for easier memorization
- arrows placed directly on home position

### Blue

Intended for number-pad and function keys.

![mitosis:datagrok layout blue layer](https://i.imgur.com/dDb2563.png)

- Keycodes generated for numbers, enter key, and mathematical symbols are from the alphanumeric keys, not number-pad.
  This way they are not influenced by the state of Num Lock.
  If you want to send the number-pad equivalents, just press Blue as well to access number-pad numbers in the same positions in the Purple layer.

### Purple

"Red and Blue" layer. Intended for "true" number-pad and various functions.

![mitosis:datagrok layout purple layer](https://i.imgur.com/pESzy2u.png)

- Numbers on this layer send Number-pad codes, so the result will be affected by the state of Num Lock.
- "Switch Layout" toggles the alphabet keys between QWERTY, Colemak, Dvorak, and Workman.
  Shift + "Switch Layout" stores the currently selected alphabet layout in eeprom, so the selection persists across reboots and computers.
- Adding blue to an arrow key from the red layer results in Page Up / Page Down / Home / End in an intuitive arrangement.

Keyboard layout editor sources:
[base](http://www.keyboard-layout-editor.com/#/gists/bc2d06a3203d1bc3a14ed2245cf39643)
[red](http://www.keyboard-layout-editor.com/#/gists/dbbf65f726a5522824b75117a62a321e)
[blue](http://www.keyboard-layout-editor.com/#/gists/240e807f3d7e1d3ddabe1b69ee675048)
[purple](http://www.keyboard-layout-editor.com/#/gists/9559f0f8bb1ee47677c8f2b4d766829d)

[Imgur album](https://imgur.com/a/hm4bbdM)

## Indicators

- The RGB indicator turns red, blue, or purple to indicate when the red, blue, or purple layer is active.
- When the Workman layer is active, the RGB indicator turns green.
  Currently, this means that activating e.g. the Red layer while using the Workman layout will make the indicator show yellow. (red + green.)
- The Num Lock status is shown on the Pro Micro tx LED.
- Caps Lock status is shown on the Pro Micro rx LED.
- If you attach a speaker to Pro Micro pin 5 (PC6) and compile with AUDIO_ENABLE=yes, music will be played at startup, when switching default layers, and when saving the default layer.

## Variants

Some additional compile-time options for this layout are available by editing rules.mk or compiling like so:

Normal compilation:

```make mitosis:datagrok```

Swap Space onto bottom thumb row: swaps Red/Backspace/Space/Red with Blue/Shift/Shift/Blue:

```make mitosis:datagrok MITOSIS_DATAGROK_BOTTOMSPACE=yes```

Lower baud UART. Useful when using an 8Mhz Pro Micro; corresponding changes required in wireless firmware. See rules.mk for details.

```make mitosis:datagrok MITOSIS_DATAGROK_SLOWUART=yes```

Green component of RGB LED on Pro Micro pin 4 (PD4).
Enables the use of TWI/I2C devices, which need Pro Micro pin 3 (PD1).
Modify your receiver hardware appropriately and compile with:

```make mitosis:datagrok MITOSIS_DATAGROK_I2CHACK=yes```

## Design notes

### Workman layout

- I'm learning a new physical key placement, so I might as well go all-out and use an optimal non-QWERTY layout.
  Bonus: it's easy to switch back to QWERTY on a traditional row-staggered keyboard.
  The designer of the Mitosis had [a similar experience](https://www.reddit.com/r/MechanicalKeyboards/comments/66588f/wireless_split_qmk_mitosis/dgfr22q/).

- I like the way Workman feels and some of its advantages over Colemak.
  Unfortunately, it was designed using a weighting system based on a standard
  row-staggered keyboard so is probably not as optimal as one could achieve
  on an ergonomic board like the Mitosis. Maybe run an optimizer routine after I
  determine good values for key difficulty on the Mitosis.

### 8Mhz Pro Micro

- I (used to) use a 3.3v Pro Micro clocked at 8Mhz rather than the 5v 16Mhz specified in the Mitosis design.
  That can't communicate with the connected wireless module at the default speed of 1M baud.
  The next fastest baudrate that works without errors is 250k baud.
  So if you want to do the same:

    - Set the Pro Micro clock and baud rate correctly in `rules.mk`:
      ```
      F_CPU = 800000
      MITOSIS_DATAGROK_SLOWUART = yes
      ```
    - Configure the receiver's wireless module to communicate at 250k baud in `main.c`. See https://github.com/reversebias/mitosis/pull/10
      ```
      -          UART_BAUDRATE_BAUDRATE_Baud1M
      +          UART_BAUDRATE_BAUDRATE_Baud250000
      ```

### Layout mnemonics

- Paired programming symbols (braces, brackets, parentheses) are arranged symmetrically in the Red layer.

- Arrow keys are in the home position on the Red layer.

  - Blue+Arrows = PgUp/PgDn/Home/End, which is intuitive for me and similar to what is done on Apple and some Dell keyboards.

- The number-pad: I placed the ten-key number-pad on the Blue layer.
  However, this would do the wrong thing when Num Lock was not enabled.
  Rather than attempt to manage the state of Num Lock, I arranged the normal number keys in a ten-key layout on the Blue layer instead.
  If you explicitly want the number-pad keys, "just add Red."
  (The number-pad keys are in corresponding positions on the Purple layer.)

- Number-pad add, subtract, multiply, divide, and enter do not mimic a standard number-pad layout as the numerals do.
  This is so they may share the same key positions as their alphanumeric key counterparts, where enter and slash are placed in a familiar position.

- The Function-keys are arranged to mimic the order of the ten-key pad.

- Why do I dislike [snake\_case](https://en.wikipedia.org/wiki/Snake_case) (`__variable_names_that_use_underscores_`)?
  Maybe because it's hard to type all those underscores requiring the shift key with lowercase letters that don't?
  Hypothesis: I'll be less annoyed by snake case by placing `_` at an unmodded position, right near the `space` key.


## Changelog

### Current

- The outer four thumb keys on each board aren't comfortable for use as modifiers.
  Let's try mod-tap on the pinky alpha-keys for ctrl/alt/shift.
  Note that this almost entirely abandons the use of four of the keys in the thumb-cluster, which is a significant departure from the previous version of this layout.
  If I love it and you hate it, let me know, and I'll see about forking it to a new keymap.
- To use TWI/I2C devices, I rerouted the green LED pin from Pro Micro pin 3 (PD1) to Pro Micro pin 4 (PD4). If you do the same, set `MITOSIS_DATAGROK_I2CHACK=yes`.
- Abandoned increasingly incorrect tri-state layer names "Symbols"/"Numbers"/"Functions" ~~in favor of "Raise/Lower/Adjust" used by more popular boards.~~
  Scratch that, I hated it.
  Using "Red/Blue/Purple" instead for my tri-state layer names.
- Bugfix: number-pad plus, minus, multiply, divide should be only on purple layer.
- Display caps lock status on rx LED
- More tinkering with the LED setting logic and macros but functionality hasn't changed much.

### 0.6.107

- Discard "intentionally difficult backspace" idea.
  Tab returns to left-shift.
  Del returns to Red+Backspace.
- "High Profile mode:" Swap Red/Backspace/Space/Red with Blue/Shift/Shift/Blue (placing space on lower thumb keys) using `MITOSIS_DATAGROK_BOTTOMSPACE=yes` when compiling.
- Move Print Screen / Scroll Lock / Pause to pinky column on Blue layer.
- Let's try using TT instead of MO so we can e.g. lock-on the number-pad.
  - We still use MO for first modifier, so e.g. Red + tapping Blue will lock purple.
    So far it feels a bit janky, we'll see.
- One key `KC_LAYO` to cycle through available base layers instead of a dedicated key for each;
  Shift + `KC_LAYO` stores current base layer selection in eeprom so it comes back after disconnecting or a reset.
- Added Colemak and Dvorak as default layers that may be selected.
- Set UART to 250kbaud with make argument `MITOSIS_DATAGROK_SLOWUART=yes`, for use with 8Mhz Pro Micros.
- Display Num Lock status on tx LED

### 0.6.60

- Experiment: no-modifier underscore on right shift key.
- New combined numbers + number-pad arrangement.
  No more worrying about Num Lock key.
- Move F-keys to left board to make room.
  Calling them "the Numbers layer" and "the Functions layer" is now less accurate but the arrangement feels better.
- Audio working!
- Move Tab and Space to upper thumb row.
  I discarded the high-profile acrylic case from my Mitosis.
  With a low-profile case, it's easier to hit the upper row of thumb keys.
- Discard all my `#defines` for "Meta", "Super", and "Hyper".
  I can call them that without making the code confusing to others.
- Move Backspace to Red+A. I shouldn't be using it much anyway.
  This means Tab and Shift might as well be separate keys again.
- Distribute paired symbols symmetrically across boards like `\<{([ ])}>/`.
  Opening-symbols on the right hand was a failed experiment. 
- Change default back to target a 16Mhz/5v Pro Micro.
  I damaged the 8Mhz Pro Micro I was using so now I'm back to using a 16mhz Pro Micro again.

### 0.6.1

- Place Tab on Shift without a modifier. We use it frequently for autocomplete.
- Make QWERTY the default layout. So more people can try it out. My customized Workman is easily toggled-on.
- Don't use redundant `#define` for `KC_TRNS`
- Place Num Lock somewhere. Otherwise (if it gets turned off) we can't type any numbers!
- Add some media keys

### 0.5.155

- Enable use with my 3.3v Pro Micro
- Add a toggle-able QWERTY layer
- Golf down the LED-setting code
- Place `!` and `?` on `Shift`+`,` and `Shift`+`.`.
- Distribute paired symbols symmetrically across boards like `\)}]> <[{(/`

### 0.5.129

- A modified Workman variant for Mitosis
- Arrows in home position, modifier + Arrow = PgUp/PgDn/Home/End
- Load all paired symbols onto angle-bracket keys.

### Abandoned ideas

- Abandoned: intentionally-difficult backspace.
  "Backspace is one of the keys I most dislike on a QWERTY keyboard because it moves me away from homerow and I need to use it so often.
  Rather than make it easier to strike, I want to discourage myself from using it and train myself to type more accurately."
  
    - Many other people like an easy-to-reach backspace.
    - Many other split-spacebar ergo boards place backspace at the thumbs.
    - I can still train myself to type well with it in an easy location.
    - I couldn't think of anything really better to put opposite space.

- Abandoned: pile all brackets onto one pair of keys.
  "Since QWERTY and Workman keep angle brackets together, place other enclosing symbols on the same keys."

    - I didn't like having to pick the right modifier to get the right flavor of bracket.
      Instead, now, one modifier activates a layer where all brackets are easily accessible.

- Abandoned: chorded Enter without proper chording detection

    - I tried to make Red+Space = Enter with the intention that I could hit both at once with one thumb.
      That didn't work well; I would often trigger space first when mashing the keys simultaneously.
      ~~This might not continue to be true if I change the angle at which I strike the keys e.g. with a neoprene base or a wrist support.~~
      Even with a wrist rest or low-profile, this is hard to do with one hand.
      Need to adjust the firmware to understand chorded thumb keys.

## To do

- When audio is disabled, there's no indication of which keymap layer you're on, except solid green on workman.
  Make this blink a pattern or something instead.
- Mod-tap to share `Ctrl` with `A` might interfere with games that assume WASD-style controls.
  But I never play games these days. :(
  Figure out a workaround?
  Maybe a "Gaming layer"?
- **Shared Layouts.**
  Figure out how to make use of QMK's common `layouts/`
- **Chorded Combos.**
  Since the thumb keys are arranged such that it's easy to smash pairs of keys with just one thumb, figure out how to enable chording.
  For example, a single-finger Shift+Space or Red+Space that doesn't do the wrong thing if Space happens to trigger first.
- Improve **LED indications** (may require modding bluetooth firmware):
    - Is any board nonresponsive (which one?)
    - Does either board have a low battery?
    - Use the green indicator for "status good" notifications, not for my favorite layout.
      - Don't mix green with red/blue; turn them off first and turn them back on when done.
    - Figure out how to blink patterns 
- **Num Lock management.**
  Num lock currently occupies prime real estate, but I never use it except to fix it when it's wrong.
  Do any of my applications use it?
  Should I have the firmware ensure it is set how I want it?
  Maybe cause it to be momentary active with Blue?
  See [@drashna's comment](https://github.com/qmk/qmk_firmware/pull/2366#issuecomment-404951953) for code to force it always-on, which I don't know if I want.
- Allow "!? on ,." to be easily toggled-off.
- Modularize "!? on ,." so it can be easily used on any QMK keyboard. (about half done)
- See if the henkan/muhenkan placement is at all useful for Japanese speakers, or abuse different keysyms for Left/Right Hyper.
  (Original space cadet used scancodes 145/175.
  145 is LANG2, 175 is "reserved" in USB HID spec.)
- Implement "layer lock" key
- Feature parity with popular boards e.g. Planck?
  - Layers for ~~Dvorak, Coleman,~~ Plover
  - More music and midi stuff
  - Macros?
- Improve tri-layer behavior
- Find out what `update_tri_layer_state` offers that my simple layers arrangement lacks.

[Workman]: https://viralintrospection.wordpress.com/2010/09/06/a-different-philosophy-in-designing-keyboard-layouts/
