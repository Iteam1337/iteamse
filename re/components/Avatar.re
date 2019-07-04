[@bs.module] external md5: string => string = "md5";

module Gravatar = {
  [@react.component]
  let make = (~email) => {
    let hash = md5(email);
    let src = {j|https://www.gravatar.com/avatar/$hash?s=300|j};

    <img className="rounded-full" src alt="" />;
  };
};

module Contentful = {
  [@react.component]
  let make = (~src) => {
    <img className="rounded-full" src alt="" />;
  };
};
