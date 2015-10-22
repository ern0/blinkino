# blinkino

**This document is in very early stage. Don't read it. You've been warned!**

## Why do we need another general-purpose Arduino library?

Arduino programming model is very simple: in the `setup()` function you prepare hardware and software components, then `loop()` will run forever and do the job. If you are not an experienced programmer, you will get stuck as soon as you want to do more tasks at once. If you want to blink *two leds* in different tempo, say, 1 Hz (1 blink / sec) and 2 Hz, it is still simple, but adding a 3rd led with, say, 7 Hz requires a better construction than a single  `loop()`. 

And it's only led blinking; if we want to download some data (e.g. check notifications) from a web server, the web client will block all other tasks in `loop()`.

## Who will use this library?

Blinkino is a set of simple C++ classes which makes easy to create
- Arduino applications performing more tasks with
- fancy blinking notifications.

This library is lightweight, I assume any programmer with some C/C++ background can write similar in a night (just as I did). Probably they don't even want to use it, or can write better one within an hour, which fits better to their actual project.

But I recommend it for makers, they can use it to create more complex applications, and I recommend it for beginner programmers, probably it helps them to understand how OOP works.

## How to use

Application is organized to one or more tasks. A task is a separate class, which is derived from the abstract Task class. The task should define states:
- each state has its ID,
- each state has its method (function), which performs the job assigned to state, and schedule the next state (which state to run next, when).

Between the states there's a chance to other tasks to perform their jobs. This is a basic form of cooperative multitasking, it requires no sophisticated task scheduler, no memory management, no multiple tasks, but if any program hangs, other programs will never run.

## TimerInterrupt class

This class is the base of task scheduling and blinking. It calls `tick()` routine every 1/100 s.

## Task class

Each task should inherit from this class. It implements the state machine and primitive task scheduling. Its `tick()` method should be called from the main `tick()` method, and its `loop()` method should be called from the Arduino `loop()` function.

## Blink class

Similar to task, but has no `loop()` method to call, only `tick()`. A blink object will play a song from interrupt. It blinks the led even when there is active `loop()` in progress.

