# Desktop Robot Arm Assembly Guide

This guide explains how to assemble the 3D-printed Desktop Robot Arm using the supplied assembly illustrations. Read the complete guide before starting, and keep the robot disconnected from power during mechanical assembly.

## Before You Start

Prepare the following:

- All parts printed from [`Desktop-Robot-Arm.3mf`](Mechanical/Desktop-Robot-Arm.3mf), or from the individual STL files in [`Mechanical/STL Files/`](Mechanical/STL%20Files/)
- 3 × continuous-rotation SG90 servo motors
- 1 × 180° SG90 servo motor for the gripper
- The screws supplied with the servos
- A small Phillips screwdriver
- A deburring tool, craft knife, or fine sandpaper for carefully cleaning print residue

Before assembly:

1. Remove supports, brims, and loose material from every printed part.
2. Check that the gears turn freely and that shafts fit their corresponding holes.
3. Route servo cables away from gears and joint openings.
4. Do not force a tight part. Lightly clean or sand the mating surface and test it again.
5. Keep all servos unpowered until the mechanical movement has been checked by hand.

## Printing the Parts

The recommended starting point is [`Mechanical/Desktop-Robot-Arm.3mf`](Mechanical/Desktop-Robot-Arm.3mf). It contains all 17 mechanical parts arranged on a single build plate and retains the slicer settings used when the project was created.

The included project uses a Bambu Lab A1 profile with a 0.4 mm nozzle, 0.20 mm layer height, PLA, a textured PEI plate, and supports enabled. Before printing, open the project in Bambu Studio or another compatible slicer and verify every setting against your own printer, build plate, and filament. Rearrange the parts or use the individual STL files in [`Mechanical/STL Files/`](Mechanical/STL%20Files/) if the complete plate does not fit your printer.

### Slicer Estimate for the Included Plate

The following values come from the saved slicer estimate and may change with the printer, filament profile, support settings, or plate arrangement:

| Estimate            |              Value |
| ------------------- | -----------------: |
| Total filament      | 36.91 m / 110.08 g |
| Model filament      | 35.49 m / 105.85 g |
| Preparation time    |       6 min 16 sec |
| Timelapse time      |        4 min 4 sec |
| Model printing time |        4 hr 35 min |
| Total time          |        4 hr 46 min |

Do not send the project directly to a printer without slicing and reviewing the preview first. Check especially that supports are generated where required and that no part extends beyond the usable build area.

## Part Orientation

In each illustration, the black arrows show the insertion or joining direction. Gear teeth must mesh without being pressed tightly together. A small amount of backlash is preferable to a joint that binds.

## Step 1 — Install the First Arm Servo and Drive Gear

![Install the first servo and drive gear](Documentation/Assembly%20Images/step-01-install-servo-and-bevel-gear.png)

Insert the first continuous-rotation servo into the open servo pocket of the arm module. Keep its output shaft facing the large helical gear already positioned in the arm.

Fit the small helical drive gear onto the servo output shaft. Align the two gears so their angled teeth mesh across their full width. The small gear should sit straight on the shaft and must not rub against the arm wall.

Do not permanently tighten the gear until its axial position has been checked.

## Step 2 — Lower the Second Arm Servo into Its Housing

![Lower the second servo into the arm housing](Documentation/Assembly%20Images/assembly-guide-step-02-servo-lowering.png)

Place the 180° positional servo above the rectangular opening in the other arm module. This servo will operate the gripper. Orient its output shaft toward the circular side opening, as shown, and lower the servo vertically into the pocket.

Make sure the cable exits through an unobstructed side of the housing and is not trapped underneath the servo.

## Step 3 — Install the Servo Locking Block

![Install the servo locking block](Documentation/Assembly%20Images/assembly-guide-step-03-locking-block.png)

Insert the small locking block into the shaped opening behind the second servo. Match the block's keyed profile to the recess and press it down until it sits flush.

The block prevents the servo from lifting or shifting inside the arm. If it requires excessive force, remove it and clean the slot before trying again.

## Step 4 — Join the Two Arm Modules

![Join the two arm modules and mesh the gears](Documentation/Assembly%20Images/assembly-guide-step-04-join-bevel-gear-modules.png)

Bring the two completed arm modules together in the direction of the arrow. Guide the curved upper section over the small drive gear while aligning the joint faces and connection points.

As the modules meet, confirm that the small and large helical gears engage correctly.

## Step 5 — Fit the Large Gear Cover

![Fit the protective cover over the large gear](Documentation/Assembly%20Images/assembly-guide-step-05-install-bevel-gear-cover.png)

Position the rounded cover over the exposed large helical gear. Align its lower rails or tabs with the matching guides on the arm, then slide it into place in the direction shown.

The cover should enclose the gear without contacting its teeth. Check the gear again after installing the cover; it must still turn freely.

## Step 6 — Attach the Lower Arm Brace

![Attach the lower arm brace](Documentation/Assembly%20Images/assembly-guide-step-06-fit-lower-brace.png)

Align the long lower brace with the circular joint openings at both ends of the arm assembly. Raise it into position beneath the arm so that both holes line up with the corresponding threaded joint openings.

Make sure the brace is not twisted and that both sides sit flat before inserting the fasteners.

## Step 7 — Secure the Arm Joints

![Install the printed arm fasteners](Documentation/Assembly%20Images/assembly-guide-step-07-install-fasteners.png)

Install the printed fasteners through the two aligned joint openings. Match each fastener to the opening shown in the illustration and tighten only until the arm sections are held together.

> [!CAUTION]
> Do not overtighten printed threads. The joints must remain able to pivot, and excessive torque can split the printed layers or clamp the mechanism.

After tightening, move the arm slowly through its available range and confirm that neither joint binds.

## Step 8 — Attach the Arm to the Rotating Platform

![Slide the arm assembly onto the circular rotating platform](Documentation/Assembly%20Images/assembly-guide-step-08-attach-circular-base.png)

Align the lower rail of the arm assembly with the matching channel on the circular rotating platform. Slide the platform onto the arm in the direction shown until the end stop and retaining features line up.

Keep the platform level during insertion. Do not bend the rail or force the connection at an angle.

## Step 9 — Lock the Arm onto the Platform

![Install the curved base retaining clip](Documentation/Assembly%20Images/assembly-guide-step-09-install-base-clip.png)

Place the curved retaining clip into the open section of the platform's outer track. Align its end tabs with the matching slots and press or slide it into position.

Check that the clip sits level with the surrounding rim and prevents the arm assembly from sliding back out of the platform.

## Step 10 — Insert the Base-Rotation Servo

![Insert the base servo into the rotating-base housing](Documentation/Assembly%20Images/assembly-guide-step-10-install-base-servo.png)

Lower the third continuous-rotation servo into the rectangular holder inside the rotating-base housing. Orient its output shaft toward the open side and cable passage shown in the illustration.

Route the servo wire through the available opening before the upper platform is installed. Verify that the servo is fully seated and stands square in its holder.

## Step 11 — Secure the Base Servo

![Secure the base servo with its mounting screws](Documentation/Assembly%20Images/assembly-guide-step-11-secure-base-servo.png)

Use the servo mounting tabs and suitable servo screws to secure the motor to its internal holder. Start both screws before tightening either one fully, then tighten them evenly.

The servo body must not move in its holder, but the screws should not crush the plastic tabs or printed mounting surface.

## Step 12 — Install the Base Drive Gear and Upper Platform

![Install the base drive gear and lower the upper platform](Documentation/Assembly%20Images/assembly-guide-variant-step-12-with-bevel-gear.png)

Fit the base drive gear onto the output shaft of the servo installed in Steps 10–11. Secure it using the appropriate servo-horn screw, if required by your servo and gear fit.

Carefully lower the completed arm-and-platform assembly into the rotating-base housing. Feed the servo wires through the intended passage and make sure none of them cross the drive gear or become pinched between the two circular parts.

## Step 13 — Join the Rotating Base to the Ring-Gear Base

![Join the rotating assembly to the static ring-gear base](Documentation/Assembly%20Images/assembly-guide-step-13-install-ring-gear-base.png)

Align the base drive gear with the internal ring gear in the static lower base. Lower the rotating assembly vertically over the center post while guiding the drive gear into the ring-gear teeth.

The rotating base should sit flat and remain centered. Turn it slowly by hand through a short arc and check that the drive gear stays engaged without jamming or climbing out of the ring gear.

## Step 14 — Install the Gripper Jaws

![Slide the left and right gripper jaws into place](Documentation/Assembly%20Images/assembly-guide-step-14-install-gripper-jaws.png)

Slide the grippers into the two guides at the front of the arm. Orient both racks so their teeth face inward toward the center, as shown.

Insert the jaws evenly and position them at approximately equal distances from the center. Both jaws should slide freely along their guides without lifting or twisting.

## Step 15 — Install the Gripper Synchronizing Gear

![Install the middle gear between the gripper jaws](Documentation/Assembly%20Images/assembly-guide-step-15-install-gripper-gear.png)

Place middle gear between the two jaw racks and onto the gripper-servo output shaft. Engage the gear with both racks at the same time so that rotating it moves the jaws symmetrically in opposite directions.

Before tightening the gear, manually move the gripper through its usable range. Confirm that:

- Both jaws remain equally spaced from the center.
- The gear stays engaged with both racks.
- The jaws do not collide at the closed position.
- The racks do not leave their guides at the open position.

## Final Mechanical Checks

Before connecting the electronics or applying power:

1. Check every cover, clip, fastener, and servo mount for looseness.
2. Move each joint slowly by hand and listen for scraping or clicking.
3. Confirm that every gear remains fully engaged throughout its movement.
4. Make sure all servo cables are clear of gears, joint pivots, and the rotating-base track.
5. Place the robot on a flat, stable surface.
6. Verify that the rotating base cannot separate from the static base when lifted gently.

After the mechanical checks pass, follow the wiring, firmware installation, calibration, and operating instructions in the main [`README.md`](README.md).

> [!WARNING]
> Perform the first powered test at low load with space around the robot. Be ready to disconnect the 5 V supply if a motor stalls, a gear skips, a wire is pulled, or the ESP32 repeatedly resets.
