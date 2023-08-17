[@react.component]
let make = () => {
  let (word, setWord) = React.useState(() => "");

  let (echo: option(Types.Echo.echo_t), setEcho) =
    React.useState(() => None);

  let form =
    <form
      onSubmit={e => {
        ReactEvent.Form.preventDefault(e);
        // let word = ReactEvent.Form.target(e)##word##value;
        Api.fetchEcho(~word)
        |> Js.Promise.then_(result => {
             switch (result) {
             | Error(_msg) => ()
             | Ok(echo) => setEcho(_ => Some(echo))
             };
             Js.Promise.resolve();
           })
        |> ignore;
      }}>
      <input
        type_="text"
        name="word"
        value=word
        onChange={e => setWord(_ => ReactEvent.Form.target(e)##value)}
      />
      <input type_="submit" value="Echo" />
    </form>;

  <div>
    form
    <br />
    {if (Belt.Option.isSome(echo)) {
       Belt.Option.map(echo, e => e.echo)->Belt.Option.getUnsafe->React.string;
     } else {
       React.null;
     }}
  </div>;
};
