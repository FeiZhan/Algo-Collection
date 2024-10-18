# StreamBase

##### Steps to Use

1. Double click `bin/StreamBaseServer.exe`.
1. Double click `bin/StreamBaseClient.exe`.
1. Input a datatype in `StreamBaseClient.exe` (e.g. `integer`, `float`, `string`), then input a value (e.g. `1`).
1. Type `storage`, then type `peek`.
1. Type `complex`, then type `1,2`.
1. Type `complex`, then type `abs`.

##### Things to note

* I used cmake to compile, visual studio code to write and debug, git and bitbucket.com to revision control.
* The server code is in `./server`, the client code is in `./client`, other common code is in `./common`.
* If you pass `async` into StreamBaseClient, it starts with asynchronous mode. StreamBaseServer always has 1 second delay to mock remote access.
* A custom class `Complex` and some methods are defined. The client can create, retrieve, and call methods on them.
* All values and objects are stored in the server. Calling `storage peek` can retrieve the previous one.
* A mutex is used before accessing the shared storage.
* A custom exception `Exception` is used to manage error handling.

##### Contacts

Fei Zhan (fei.zhan.zju@gmail.com)
