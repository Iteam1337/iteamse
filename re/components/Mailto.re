[@react.component]
let make = (~email) => {
  <a className="border-b-2 border-white" href={"mailto:" ++ email}>
    {React.string(email)}
  </a>;
};
