# 🚧 pre-release note 🚧
👷‍♂️ This repository is still a work-in-progress, please be patient, things will likely change daily

# RC Pilot Table
:airplane: This is a height adjustable, auto leveling table, intended for RC pilots. This table uses four [linear actuators](https://www.amazon.com/dp/B00NM8H67C/?coliid=I13O6CUFJ1UPBA&colid=PGYE4HTR4F8&psc=1&ref_=list_c_wl_lv_ov_lig_dp_it) as legs.

:wheelchair: No crossmembers and a shallow deck make it usable for all pilots, including those using a wheelchair. 

:wrench: The table height adjusts simply via a rocker switch. It levels itself via a pushbutton. It is designed for outdoor use and runs on 2S-8S battery power.

![](/drawings%20and%20images/IMG_9872.png)

## Project origin

Initially, I did not see an issue with the tables at my local AMA field. They are a common design, made of affordable materials and mostly construction wood. This design builds on (dare I say improves?) prior art as featured here:

![](https://modelaviation.s3.us-east-2.amazonaws.com/08bench01-600.jpg?VersionId=744QaEbHNXa4dHiNFX8TMIt47bCXdaZG)

source: https://www.modelaviation.com/Club-Field-Safety-Benches

One day, a fellow pilot pointed out that they were difficult for him to use. This is when I realized that any table that has crossmembers connecting the legs is inaccessible for a pilot who uses a wheelchair. My friend also explained that a higher working surface would be nice to have. A feys days later, I learned from another club member that a lower table surface would be better suited for his needs. I realized that a better table has to height adjustable.
A web search for an off-the-shelf solution yielded no convincing options and neither did my seach for better open source designs. So I decided to come up with my own solution.

## How to operate
Safety first: This is a prototype. Stay clear of moving parts and use it at your own risk. Only plug in a battery while using it and be ready to unplug if anything unexpected happens. Don't leave a battery plugged in unattended.

The table has an internal 8-36V buck/boost power regulator, so it can handle anything from 2S to 8S battery. Simply plug your pack into the XT60 connector. I don't have exact numbers on the current draw, but obviously it will be higher for lower voltage packs. Very small 2S or 3S packs might not have enough punch.

Use the rocker switch to adjust the deck to the desired height, or slightly below it. Then use the leveling button and watch the magic happen. The table will attempt to raise the corners until the deck is level. Leveling happens upwards, so start it below the desired height. The code will time out after a few seconds, press the button again as needed. The software is not very sophisticated yet. Press down on a corner and level it again if the table teeters.   

## How to build
A detailed build guide or a build video will follow. For the time being, I an providing the FreeCAD drawings, electrical schematics and STLs in the subfolders

### Lumber
I chose to only use only one type of lumber for the entire build. This reduces waste and makes purchasing easier for the hobbyist. 2 in. x 6 in. dimensional lumber is readily available at hardware stores and local lumber yards. I built the first prototype from green western red cedar, but any hardwood or SPF will work the same depending on climate and weather, how long you want your table to last, how good you want it to look and how much $ you're willing to spend.

You need a total of ~ 50ft:

| count | length | use
| --- | --- | ----
| 6 pcs | 60" | for deck
| 3 pcs | 32" | for deck support
| 2 pcs | 15" | for side boards (optional, need to be fitted)
| 16 pcs| 6" | for the leg housing sides
| 4 pcs | 2"  | (from scraps) for the leg housing bottoms

### Legs - linear actuators


### 3D Prints
The STLs are posted here. As filament, I am using either Polymaker ASA or Priline TPU. 
### electrical box
I chose printing the box because I can skip several work steps and iterate faster this way. It also allows having a two colored front plate by stopping the print and changing color after a few layers. An off the shelve electrical enclosure will work just as well though.
### feet
The feet are printed in TPU at 100% infill. 
### vertical wing restraint hanger
The vertical wing restraint is removable (credits?) PVC pipe. It can be inserted into holes on the table to provide a hard stop for fixed-wing aircraft during setup and testing. Since these are not needed all the time, the restraints are removable and I designed a simple hanger to stow them when not in use.
The hanger is printed in ASA. I'm sure there is an injection molded substitute somewhere, but I couldn't find anything I liked.

### router template
This print is used a jig to help making cutting the bottom of the leg housing. The linear actuator has to be tightly held or else the table would get wiggly. Use this template to hold and cut the wooden bracket.

### Amazon - what I bought
These are not affiliate links and I am not trying to monetize or profit of this project. Please also don't consider these reviews or recommendations. The amazon link below simply takes you to a list of all the stuff that I personally bought and used during the build. It is not a comprehensive list either, but I think it might be helpful nevertheless.  

[Amazon list](https://www.amazon.com/hz/wishlist/ls/PGYE4HTR4F8?ref_=wl_share)

## Height adjustment
I chose to use linear actuators for height adjustable legs. The rest of the table is designed is driven by this decision. The actuators are marketed for use with solar panels, so they are weather resistant and affordable enough at around ~$50 a piece at time of writing. They are however also not very precise, consistent or repeatable in their positioning and additional electronics are required to maintain a level surface and prevent rocking.

## What's next
- better software
- better build guides
- record build videos

## License
Unless otherwise noted, this work is licensed under a
[Creative Commons Attribution 4.0 International License][cc-by].

[![CC BY 4.0][cc-by-image]][cc-by]

[cc-by]: http://creativecommons.org/licenses/by/4.0/
[cc-by-image]: https://i.creativecommons.org/l/by/4.0/88x31.png
[cc-by-shield]: https://img.shields.io/badge/License-CC%20BY%204.0-lightgrey.svg
