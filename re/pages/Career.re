[@react.component]
let make = (~data) => {
  let {contactTitle, header, hiringTitle as _ht, contacts}: Page.Career.t =
    Page.Career.make(data);

  <>
    <header> <img src={header.url} alt="" /> </header>
    <main
      className="grid-columns-1fr md:grid-columns-1024 grid-gap-10-y grid md:grid-gap-24-y my-24"
    />
    <Block.Section color=`RadicalRed>
      <Contacts title={Some(contactTitle)} contacts />
    </Block.Section>
    <Block.Section color=`Concrete>
      <div> "Hello"->React.string </div>
    </Block.Section>
  </>;
};

let default = make;
