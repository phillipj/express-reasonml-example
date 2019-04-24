// Credits to @kevinsimper for most of the very trivial bindings below
// https://medium.com/@kevinsimper/how-to-create-express-js-server-in-reasonml-97ba28173f63

type express;
type response;
type request;
type handler = (request, response) => unit;

[@bs.send] external get: (express, string, handler) => unit = "";
[@bs.send] external send: (response, string) => unit = "";
[@bs.send] external listen: (express, int) => unit = "";
[@bs.module] external express: unit => express = "express";
// bs.get gets a specific field from a JavaScript object
[@bs.get] external getQuery: request => Js.Dict.t(string) = "query";

// Convience function written to ease the pain of handling a JavaScript
// dictionary directly, but rather get a plan old option back
let getQuery = (request, queryName) =>
  Js.Dict.get(getQuery(request), queryName);