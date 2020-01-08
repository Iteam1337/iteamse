module H1 = {
  [@react.component]
  let make = (~children, ~className=?) => {
    <h1
      className={Css.merge([
        "lg:text-5xl text-3xl font-medium md:leading-snug",
        className->Cn.unpack,
      ])}>
      children
    </h1>;
  };
};

module H2 = {
  [@react.component]
  let make = (~children, ~className=?) => {
    <h2
      className={Cn.make([
        "text-2xl md:text-4xl font-medium leading-tight",
        className->Cn.unpack,
      ])}>
      {React.string(children)}
    </h2>;
  };
};

module H3 = {
  [@react.component]
  let make = (~children) => {
    <h3 className="text-xl md:text-3xl font-medium">
      {React.string(children)}
    </h3>;
  };
};

module H4 = {
  [@react.component]
  let make = (~children, ~className=?) => {
    <h4
      className={Css.merge([
        "text-lg md:text-2xl font-medium",
        className->Cn.unpack,
      ])}>
      {React.string(children)}
    </h4>;
  };
};
