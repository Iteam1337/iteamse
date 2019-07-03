module H2 = {
  [@react.component]
  let make = (~children) => {
    <h2 className="text-2xl md:text-4xl font-medium">
      {React.string(children)}
    </h2>;
  };
};
