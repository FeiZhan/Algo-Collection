# StreamBase

### Introduction
In this coding assignment, you will be building a client/server desktop application using C++ targetted for the Windows platform. Detailed specifications along with some other helpful information is provided below. Goodluck!

### How to approach this

You are not expected to (cumulatively) spend more than 8 hours on this task. These 8 hours can be spread over multiple days within a two week timeframe. You can start whenever you like. Please make reasonable assumptions and design choices where you feel the specification is unclear or falls short. Make sure to document your assumptions and design in the README or other relevant documents you produce (e.g. code comments).

To help you make these decisions, keep in mind that we ask candidates to complete these coding assignments in order to:

Gauge your technical strength and ability to work independently while delivering a feature complete product
Ability to navigate third-party interfaces (libraries/apis) where the documentation/spec might not be very detailed
All work you do will be your property; we are not trying to get free work done here. A couple hundred people have done this assignment previously (some are part of our team now!) and this functionality is live in our product(s).

_We internally use CMake and expect you to use the same. It is also reccomended to use the Visual Studio compiler. You are free to use any other libraries as you like with NamedPipes API being the only hard requirement for IPC._

We are expecting a link to a public git repo (Github is a famous choice) consisting:
1. `README` explaining your implementation
2. Binaries for both client and server
3. Source code

### Requirements

You are required to create two console applications using C++: 1. client 2. server; with the following features:
1. The client should be able to connect to the server through a NamedPipe
2. The client should be able to make both sync and async calls to the server
3. The client should be able to send trivial data (strings, numbers) to the server
4. The client should be able to create objects on the server (based on req-7 below), retrieve them, their attributes and call methods on them
5. The server should be able to receive  both sync/async connection requests from clients
6. The server should be able to store data provided by the client via NamedPipe in a reasonable data structure
7. The server should be able to register a custom class (w/ related functions, attributes) which can be used by the client (see req-4)
8. The server should be able to store the custom objects created by the client for the custom class created in req-7 


> Goodluck! And please feel free to ping us if you have any questions. We looking forward to having you on-board our team :)
