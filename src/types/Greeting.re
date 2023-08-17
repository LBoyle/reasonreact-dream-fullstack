type greeting_t = {greeting: string};

let decodeGreeting = (json: Js.Json.t) => {
  greeting: json |> Json.Decode.field("greeting", Json.Decode.string),
};
