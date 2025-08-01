# RC Pilot Table
:airplane: This is a height adjustable, auto leveling table, intended for RC pilots. This table uses four [linear actuators](https://www.amazon.com/dp/B00NM8H67C/?coliid=I13O6CUFJ1UPBA&colid=PGYE4HTR4F8&psc=1&ref_=list_c_wl_lv_ov_lig_dp_it) as legs.

:wheelchair: No crossmembers and a shallow deck make it usable for all pilots, including those using a wheelchair. 

:wrench: The table height adjusts simply via a rocker switch. It levels itself via a pushbutton. It is designed for outdoor use and runs on 2S-8S battery power.

![](/drawings%20and%20images/IMG_9872.png)

## comments, questions and chat
You can leave comments, reviews, ask questions or start a conversation about this project [here](https://github.com/T-RC/RCPilotTable/discussions).

## Project background

Initially, I did not see an issue with the tables at my [local AMA field](www.triplecreekrc.com). They are a common design, made of affordable materials and mostly construction wood. 

![](/drawings%20and%20images/IMG_9917.png)

I believe the design is, at least in parts, inspired by prior art as featured [here](https://www.modelaviation.com/Club-Field-Safety-Benches).

One day, a fellow pilot pointed out that these tables are difficult for him to use. I realized that any table that has crossmembers connecting the legs is inaccessible for a pilot who uses a wheelchair. He also explained that a higher working surface would be nice to have. A few days later, I learned from another club member that a lower table surface would be better suited for his needs. I realized that a better table has to be height adjustable.
A web search for an off-the-shelf solution yielded no convincing options and neither did my search for better open source designs. I decided to come up with my own solution.

I chose to use [linear actuators](https://www.amazon.com/dp/B00NM8H67C/?coliid=I13O6CUFJ1UPBA&colid=PGYE4HTR4F8&psc=1&ref_=list_c_wl_lv_ov_lig_dp_it) for the height adjustable legs. The rest of the design is driven by this decision. The actuators are marketed for use with solar panels, so they are weather resistant, IP54 rated, and affordable enough at around ~$50 a piece. They are however also not very precise, consistent or repeatable in their positioning and additional electronics are required for a level surface and to prevent rocking.

## The prototype
I have built one prototype so far. After it was finished, I donated it to the [Triple Creek Radio Control Aircraft Club](www.triplecreekrc.com) where it is in use since July 2025. The Tripple Creek RC field is located at 12705 Balm Boyette Rd
Riverview, FL 33579. 

![](/photo%20gallery/table%20in%20use%201.png)

## How to operate
Safety first: This is still a prototype. Stay clear of moving parts and use it at your own risk. Only plug in a battery while using it and be ready to unplug if anything unexpected happens. Don't leave a battery plugged in unattended.

![](/drawings%20and%20images/IMG_9914.png)

The table has an internal 8-36V buck/boost power regulator, so it can handle anything from 2S to 8S battery. Simply plug your pack into the XT60 connector. I don't have exact numbers on the current draw, but obviously it will be higher for lower voltage packs. Very small 2S or 3S packs might not have enough punch.

Use the rocker switch to adjust the deck to the desired height, or slightly below it. Then use the leveling push-button and watch the magic happen. The table will attempt to raise the corners until the deck is level. Leveling happens upwards, so it's best to start below the desired height. The software code will time out after a few seconds, press the button again as needed. The programming is not very sophisticated yet. Press down on a corner and level it again if the table teeters.   

## How to build
A detailed build guide or a build video will follow if there is interest in it [(feel free to leave a comment here)](https://github.com/T-RC/RCPilotTable/discussions). For the time being, I an providing the [FreeCAD](https://www.freecad.org/) drawings, electrical schematics and STLs in the [subfolders](/drawings%20and%20images).

![](/drawings%20and%20images/table%20assembly%20view.png)

### Lumber
I chose to only use one kind of timber for the entire build. This reduces waste and makes purchasing easier for us hobbyists. 2 in. x 6 in. dimensional lumber is readily available at hardware stores and local lumber yards. I built the first prototype from green western red cedar, but any hardwood or SPF will work the same depending on climate and weather, how long you want your table to last, how good you want it to look and how much $ you're willing to spend.

You need a total of approximately 50ft:

| count | length | use
| --- | --- | ----
| 6 pcs | 60" | for deck
| 3 pcs | 32" | for deck support
| 2 pcs | 15" | for side boards (optional, need to be fitted)
| 16 pcs| 6" | for the leg housing sides
| 4 pcs | 2"  | for the leg housing bottoms, use jig to cut

### Legs - linear actuators
The legs I used are [linear actuators](https://www.amazon.com/dp/B00NM8H67C/?coliid=I13O6CUFJ1UPBA&colid=PGYE4HTR4F8&psc=1&ref_=list_c_wl_lv_ov_lig_dp_it) from Amazon.
### 3D Prints
I used [FreeCad](https://www.freecad.org/) for all the designs and [all drawings are here](/drawings%20and%20images). The STLs are posted [here](/3D%20print%20STLs). As filament, I am using either [Polymaker ASA](https://www.amazon.com/dp/B09DKQK318/?coliid=I2VLWN38FZA86A&colid=PGYE4HTR4F8&psc=1&ref_=list_c_wl_lv_ov_lig_dp_it) or [Priline TPU](https://www.amazon.com/dp/B0BJ5XRDFB/?coliid=I2SHOWQPSHQ9XM&colid=PGYE4HTR4F8&psc=1&ref_=list_c_wl_lv_ov_lig_dp_it). 
### electrical box
I chose 3D-printing the box because I can skip several work steps and iterate faster this way. It also allows having a two colored front plate by stopping the printer and changing color after a few layers. An [off the shelve electrical enclosure](https://www.amazon.com/dp/B08N1DD5WJ/?coliid=I3T08VJ4IFBYYQ&colid=PGYE4HTR4F8&psc=1&ref_=list_c_wl_lv_ov_lig_dp_it) will work just as well though.
### feet
The feet are 3D-printed in TPU at 100% infill.
### vertical wing restraint hanger
The vertical wing restraint is a removable design made from PVC pipe (not my idea, who get's credit?). It can be inserted into holes on the table to provide a hard stop for fixed-wing aircraft during setup and testing. Since these are not needed all the time, the restraints are removable and I designed a simple hanger to stow them when not in use.
The hanger is 3D-printed in ASA. I'm sure there is an injection molded substitute somewhere, but I couldn't find anything I liked so I designed my own.

### router template
This 3D-print is used as a jig to help cutting the bottom of the leg housing. The linear actuator has to be tightly held or else the table would get wiggly. Use [this template](/3D%20print%20STLs/Router%20template.stl) to hold and cut the wooden brackets.

### Amazon - what I bought
These are not affiliate links and I am not trying to monetize or profit of this project. Please also don't consider these reviews or recommendations. The Amazon link below simply takes you to a list of all the stuff that I personally bought and used during the build. It is not a comprehensive list either, but I think it might be helpful nevertheless.  

[Amazon list](https://www.amazon.com/hz/wishlist/ls/PGYE4HTR4F8?ref_=wl_share)

## What's next
- My next step is to record a build video for the electrical box
- Maybe a full build video as well
- The software can still use some work
  
let me know what you think [here](https://github.com/T-RC/RCPilotTable/discussions)


## License
Unless otherwise noted, this work is licensed under a
[Creative Commons Attribution 4.0 International License][cc-by].

[![CC BY 4.0][cc-by-image]][cc-by]

[cc-by]: http://creativecommons.org/licenses/by/4.0/
[cc-by-image]: https://i.creativecommons.org/l/by/4.0/88x31.png
[cc-by-shield]: https://img.shields.io/badge/License-CC%20BY%204.0-lightgrey.svg


[![CC BY 4.0][cc-by-image]][cc-by]

[cc-by]: http://creativecommons.org/licenses/by/4.0/
[cc-by-image]: https://i.creativecommons.org/l/by/4.0/88x31.png
[cc-by-shield]: https://img.shields.io/badge/License-CC%20BY%204.0-lightgrey.svg
