module App = {
  [@react.component]
  let make = () => {
    let message = Some("Welcome to the React+Dream ReasonML fullstack");
    if (Belt.Option.isSome(message)) {
      Belt.Option.getUnsafe(message)->React.string;
    } else {
      "Failed to load Belt"->React.string;
    };
  };
};

ReactDOM.querySelector("#root")
->(
    fun
    | Some(root) => ReactDOM.render(<App />, root)
    | None =>
      Js.Console.error(
        "Failed to start React: couldn't find the #root element",
      )
  );
