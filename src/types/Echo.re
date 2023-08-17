type echo_t = {echo: string};

let decodeEcho = (json: Js.Json.t) => {
  echo: json |> Json.Decode.field("echo", Json.Decode.string),
};
