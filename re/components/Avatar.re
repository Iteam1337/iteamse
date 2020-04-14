[@bs.module] external md5: string => string = "md5";

module Image = {
  [@react.component]
  let make = (~src) => {
    <img
      className="w-1/2 md:w-full rounded-full hover:shadow-2xl hover:-translate-y-6px transition-250
      transition"
      src
      alt=""
    />;
  };
};

module Gravatar = {
  [@react.component]
  let make = (~email) => {
    let hash = md5(email);
    let src = {j|https://www.gravatar.com/avatar/$hash?s=300|j};

    <Image src />;
  };
};

module Contentful = {
  [@react.component]
  let make = (~src) => {
    <Image src />;
  };
};
