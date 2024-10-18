# Payments Data Server

This is a mock server for a Circle Internet Financial interview problem.  It is a Node.js server that produces a stream of data describing peer-to-peer payments.  It has three endpoints, described below, that your interview problem will probably ask you to interact with in some fashion.  You'll need to start up and run the server for your development environment, for which there are instructions below.  You may not modify the server's code to support your answer, though you're welcome to read through it if that's useful to you.


## Starting the Server

Make sure you have the following prerequisites installed:
  - [Node 12 or better](https://nodejs.org/en/)
  - [Yarn](https://classic.yarnpkg.com/en/docs/install/#mac-stable)

Make sure you do not have anything running on port 8080.  Once you have done so, install the Node dependencies and start the Express server by running the following commands in this directory:
```bash
$ yarn install
$ yarn start
```

You can then test that the server is running by curling it.  You should receive something like the following (the format is described below):
```bash
$ curl localhost:8080/payments
{"data":{"id":"1508200420066714","date":"2020-10-07T20:59:37.000Z","sender":{"id":105,"name":"Jensen Mertz"},"receiver":{"id":100,"name":"Haley Buxton"},"amount":"6194.45","currency":"EUR","memo":"hamburgers and orange juice"}}
```


## Server Endpoints

The server has three endpoints.  Your problem may ask you to interact with some or all of them.  If your problem requires you to interact with a given endpoint then you must interact with it, but if it does not mention a given endpoint you are still welcome to use it if doing so would be helpful to you.  The endpoints are:

  - GET Payments
  - POST Payments
  - GET Users


### GET Payments

This endpoint, `GET /payments`, returns a JSON object describing a single peer-to-peer payment.  Every second, the payment that is returned changes, but if you query the endpoint multiple times within the same clock second you will receive the same data.  The format of the response is as follows:

```json
{
    "data": {
        "id": "stringified long number",
        "date": "stringified ISO-8601 timestamp",
        "sender": {
            "id": "number",
            "name": "string"
        },
        "receiver": {
            "id": "number",
            "name": "string"
        },
        "amount": "stringified decimal number",
        "currency": "stringified ISO-4217 currency code",
        "memo": "string"
    }
}
```

You can curl the endpoint to receive the data:

```bash
$ curl localhost:8080/payments
```

```json
{
  "data": {
    "id": "1508200420066714",
    "date": "2020-10-07T20:59:37.000Z",
    "sender": {
      "id": 105,
      "name": "Jensen Mertz"
    },
    "receiver": {
      "id": 100,
      "name": "Haley Buxton"
    },
    "amount": "6194.45",
    "currency": "EUR",
    "memo": "hamburgers and orange juice"
  }
}
```

This represents a payment from Jensen to Haley on October 7th, 2020, for €6194.45 as repayment for hamburgers and orange juice.

Please note that because of how the random data is generated, the ids and names of users will not be consistent between runs of the server.  However, within a given run, a given user id will always map to the same user name.


### POST Payments

This endpoint, `POST /payments`, allows you to create a new payment on the server.  It uses the same data format as `GET /payments` (an example is given below).  It does some simple validation on the input, records the payment, and returns a 201 error code.  Unfortunately, the server is flaky, and so half the time the payment will fail with a 503 error code.  Once a payment succeeds, you cannot re-use the same payment id or the endpoint will fail with a 409 error code.

To create a payment, POST to `/payments` with a JSON body containing the same data format as the `GET /payments` endpoint returns.  Your input must have the following properties:
  - `id` must be a string, and once an id has been used to make a successful payment it can never be used again
  - `date` must be a string that the native Javascript `Date` class can parse
  - `sender` must be a valid user object, described below
  - `receiver` must be a valid user object, described below
  - `amount` must be a string that Javascript can parse to a float
  - `currency` must be one of `BTC`, `GBP`, `EUR`, `JPY`, or `USD`
  - `memo` may be included, but it is not validated

A valid user object is a JSON object with `id` and `name` properties (just like the `GET /payments` endpoint returns).  `id` must be an integer and `name` a string.  Additionally, the sender and receiver ids and names must match actual users in the system.  The users are randomly generated each time the server is restarted, and so you'll need to make sure to give valid user ids and names.  The server prints out a list of ids and names to the console when it starts up, and you can also use the `GET /users` endpoint described below to list them programmatically.  Finally, the sender and receiver must be different.

So, you can create a payment by using the following curl example, after updating it to have valid ids and names for your run of the server:
```bash
$ curl localhost:8080/payments -H 'Content-type: application/json' --data '{"id":"1508200420066714","date":"2020-10-07T20:59:37.000Z","sender":{"id":100,"name":"Haley Buxton"},"receiver":{"id":101,"name":"Chloe Seibert"},"amount":"123.45","currency":"USD","memo":"hamburgers and orange juice"}'
```

There are 5 different response codes that the server may return:
  - `201`: Payment was successful
  - `400`: Invalid input, wih an error message explaining which property is wrong
  - `409`: Payment id was already used
  - `500`: General internal server error (this isn't intentionally returned, so if you get this error you probably made a bad request)
  - `503`: Flaky server; please try again

Please note that payments created via this endpoint will not show up in the `GET /payments` endpoint.


### GET Users

This endpoint, `GET /users`, returns a list of all generated users in the system.  You can query it as follows:
```bash
$ curl localhost:8080/users
{"data":[{"id":100,"name":"Haley Buxton"},{"id":101,"name":"Chloe Seibert"},{"id":102,"name":"Eugene Trevino"},{"id":103,"name":"Braylen Mertz"},{"id":104,"name":"Connor Muse"},{"id":105,"name":"Jensen Mertz"},{"id":106,"name":"Zechariah Carbone"},{"id":107,"name":"Jane Leo"},{"id":108,"name":"Bianca Barnard"},{"id":109,"name":"Kaleb Branson"},{"id":110,"name":"Ray Halstead"},{"id":111,"name":"Natasha Shrader"},{"id":112,"name":"Danna Mcewen"},{"id":113,"name":"Gage Kidd"},{"id":114,"name":"Lee Rohrer"},{"id":115,"name":"Jaelynn Pettigrew"},{"id":116,"name":"Augustus Button"},{"id":117,"name":"Kaliyah Somers"},{"id":118,"name":"Griffin Jacques"},{"id":119,"name":"Lee Feldman"}]}
```

Please note that because of how the random data is generated, the ids and names of users will not be consistent between runs of the server.  However, within a given run, a given user id will always map to the same user name.
