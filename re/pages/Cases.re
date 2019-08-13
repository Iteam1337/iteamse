[@react.component]
let make = (~data) => {
  let {header}: Page.Case.t = Page.Case.make(data);

  <>
    <Block.Header
      backgroundImage={header.url}
      color={header.textBgColor}
      messageOne={header.text}
      messageTwo={header.textSecond}
    />
  </>;
};

let default = make;
