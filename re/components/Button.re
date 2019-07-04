module Secondary = {
  [@react.component]
  let make = (~href, ~children) => {
    <a
      className="border border-black rounded font-normal py-2 px-5 inline-block"
      href>
      {React.string(children)}
    </a>;
  };
};
