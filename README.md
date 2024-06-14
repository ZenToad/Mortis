# mortis
Got it. You're dealing with the order of module initialization and dependencies. One approach is to use a very basic, built-in logging mechanism for the initialization phase. This can be replaced by your more advanced logger once the necessary modules are loaded.

Here's how you might do it:

Bootstrap Logger:

Implement a very simple, statically defined logger within your main framework or a separate bootstrap module.
This logger can write to a predefined memory buffer or directly to a console/file.
Module Initialization:

Initialize your memory management module.
Initialize your string handling module.
Use the bootstrap logger to log any critical errors during this phase.
Advanced Logger:

Once the memory management and string modules are loaded, initialize your full-featured logger.
Redirect log messages from the bootstrap logger to the advanced logger.
Optionally, you can transfer any buffered log messages from the bootstrap logger to the advanced logger.
Switch Over:

Ensure all logging functions switch to the advanced logger after initialization.
This way, you have a basic logging mechanism available during the critical early stages of module loading. Once the full infrastructure is in place, you can switch to a more sophisticated logging system. Does this solution address your concern?
