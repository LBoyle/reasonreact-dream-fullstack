// do env vars for switching port in dev mode

let fetchGreeting = () => {
  Js.Promise.(
    Fetch.fetch("/api")
    |> then_(Fetch.Response.json)
    |> then_(response => {
         resolve(
           switch (Types.Greeting.decodeGreeting(response)) {
           | greeting => Ok(greeting)
           | exception exn =>
             Js.log2("Failed to decode greeting: ", exn);
             Error("Failed to decode greeting");
           },
         )
       })
    |> catch(exn => {
         Js.log2("Error getting greeting: ", exn);
         resolve(Error("Error getting greeting"));
       })
  );
};

let fetchEcho = (~word) => {
  Js.Promise.(
    Fetch.fetch("/api/echo/" ++ word)
    |> then_(Fetch.Response.json)
    |> then_(response => {
         resolve(
           switch (Types.Echo.decodeEcho(response)) {
           | echo => Ok(echo)
           | exception exn =>
             Js.log2("Failed to decode echo: ", exn);
             Error("Failed to decode echo");
           },
         )
       })
    |> catch(exn => {
         Js.log2("Error getting echo: ", exn);
         resolve(Error("Error getting echo"));
       })
  );
};
