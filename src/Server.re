open Express;

let app = express();
let port = 3000;

get(app, "/", (request, response) => {
  send(response, "Vrrooooom!");
});

get(app, "/echo", (request, response) => {
  let name = getQuery(request, "name");

  send(response, "Hello there" ++ name ++ "!");
});

listen(app, port);