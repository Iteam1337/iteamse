module H1 = {
  [@react.component]
  let make = (~children) => {
    <h1 className="md:text-5xl text-2xl font-medium"> children </h1>;
  };
};

module H2 = {
  [@react.component]
  let make = (~children) => {
    <h2 className="text-2xl md:text-4xl font-medium">
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
  let make = (~children) => {
    <h4 className="text-lg md:text-2xl font-medium">
      {React.string(children)}
    </h4>;
  };
};
