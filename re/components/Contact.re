module Mailto = {
  [@react.component]
  let make = (~email, ~className=?) => {
    <div>
      <a
        className={Css.merge([
          "border-b border-solid border-current",
          className->Cn.unpack,
        ])}
        href={"mailto:" ++ email}>
        {React.string(email)}
      </a>
    </div>;
  };
};

module Telephone = {
  [@react.component]
  let make = (~phoneNumber, ~className=?) => {
    <div>
      <a
        href={[|"tel:", phoneNumber|]->Js.String.concatMany("")}
        className={Css.merge(["text-cornflower-blue", className->Cn.unpack])}>
        phoneNumber->React.string
      </a>
    </div>;
  };
};
