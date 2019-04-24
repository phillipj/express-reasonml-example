open Express;
open Belt;

let app = express();
let port = 3000;

get(app, "/", (request, response) => {
  send(response, "Vrrooooom!");
});

get(app, "/echo", (request, response) => {
  let maybeName = getQuery(request, "name");
  let greeting =
    maybeName
      ->Option.map(name => "Hello there " ++ name ++ "!")
      ->Option.getWithDefault("Got no idea who you are :/");

  send(response, greeting);
});

listen(app, port);