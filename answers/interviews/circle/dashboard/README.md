# Payments Data Dashboard

This is a Circle Internet Financial interview problem to create a dashboard to display some peer-to-peer payments data.  You've been given a web server that produces some data describing a stream of peer-to-peer payments.  You should create a React.js or Vue.js web dashboard that displays the data.


## Server

You are given a web server in the `server` directory that produces the payments data.  It has a a number of endpoints, but for this exercise you will only need to interact with the `GET /payments` endpoint.  Every second it returns a different JSON object describing a single peer-to-peer payment.  If you query it multiple times within the same clock second, it will return the same sample payment.  Once the clock second has passed the endpoint will return a new sample payment, and you will be unable to retrieve the previous payment from the server again.  You may not modify the server's code, or use a different server, as part of your solution.

The `server` directory contains a `README.md` with documentation of the data format and instructions for getting the server running.


## Dashboard

Your job is to create a web dashboard to display the payments data.  It must be written in some form of [React.js](https://reactjs.org/) or [Vue.js](https://vuejs.org/), though you're welcome to use additional frameworks like [Next.js](https://nextjs.org/) or [React Redux](https://react-redux.js.org/) on top.  You may not use a completely different reactive framework like [Angular.js](https://angularjs.org/).

Your dashboard should have a single page that shows a list of the 25 most recent payments that reactively updates as the server produces new payments.  For each payment you should show the sender's name, receiver's name, amount, and currency.  You should also have a search bar that allows dynamically filtering payments based on all fields returned by the API, not just the display names, amount, and currency.  You should put a little work into your UI to make it reasonably attractive, though it doesn't have to be perfect.  Using some pre-built components from a library like [Bootstrap](https://getbootstrap.com/) will be more than enough.

As described above the server will not allow you to query past payments, so you'll need to keep and update some client-side state to display historical payments.  You may not add an intermediary server of your own; you can only write browser-side code (besides whatever HTTP server your chosen framework provides to serve its client bundle).  You don't need to worry about persisting payments data in the browser across refreshes; you can start with an empty list of payments each time the page is reloaded.


## Logistics

You should return to your recruiter a tarball containing your web dashboard that satisfies the above requirements, along with a README that describes how to get it running and any design choices you made that you think are particularly interesting.  We recognize that when job searching your time is valuable and so we think this exercise should take you about 5-7 hours; please do not feel that you need to spend much more time than that on it.  Please reach out to your recruiter if you have any questions about the exercise.  Thanks!
