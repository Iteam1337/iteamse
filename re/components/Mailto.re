[@react.component]
let make = (~email) => {
  <a
    className="border-b-2 border-solid border-current"
    href={"mailto:" ++ email}>
    {React.string(email)}
  </a>;
};
