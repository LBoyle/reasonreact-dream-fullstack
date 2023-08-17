[@react.component]
let make = () => {
  let (greeting: option(Types.Greeting.greeting_t), setGreeting) =
    React.useState(() => None);

  React.useEffect0(() => {
    Api.fetchGreeting()
    |> Js.Promise.then_(result => {
         switch (result) {
         | Error(_msg) => ()
         | Ok(greeting) => setGreeting(_ => Some(greeting))
         };
         Js.Promise.resolve();
       })
    |> ignore;
    None;
  });

  if (Belt.Option.isSome(greeting)) {
    Belt.Option.map(greeting, g => g.greeting)
    ->Belt.Option.getUnsafe
    ->React.string;
  } else {
    React.null;
  };
};
