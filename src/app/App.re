[@react.component]
let make = () => {
  <div>
    <p> {React.string("Welcome to the React+Dream ReasonML fullstack")} </p>
    <br />
    <Components.Greeting />
    <br />
    <br />
    <Components.Echo />
  </div>;
};
