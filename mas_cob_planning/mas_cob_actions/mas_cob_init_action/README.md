# mas_cob_init_action

An action for initialing the components of a robot.

## Action definition

### Goal constants:

* ``string BASE=base``
* ``string GRIPPER=gripper``
* ``string TRAY=tray``
* ``string TORSO=torso``
* ``string HEAD=head``
* ``string ARM=arm``

### Goal:

* ``string[] components``: A list of components to initialise (as specified by the above constants)

### Result:

* ``bool[] success``: A list of Booleans corresponding to whether the i-th component in ``components`` was successfully initialised

### Feedback:

* ``string current_state``
* ``string message``

## Dependencies

* ``std_srvs``
* ``moveit_commander``
* ``cob_script_server``

## Example usage

1. Run the robot simulation: ``roslaunch mas_bringup_sim jenny.launch``
2. Run the cob moveit interface: ``roslaunch mas_cob_moveit move_group.launch``
3. Run the action server: ``roslaunch mas_cob_init_action cob_init.launch``
4. Run the client example: ``rosrun mas_cob_init_action cob_init_action_client_test head torso gripper base tray arm``
