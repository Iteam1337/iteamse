[@react.component]
let make = (~data, ~illustration) => {
  let {
    ourMethodTitle,
    ourMethodText,
    weAreText,
    weAreTitle,
    weOfferText,
    weOfferTitle,
    contacts,
  }: Page.Start.t =
    Page.Start.make(data);

  <>
    <main
      className="grid-columns-1fr md:grid-columns-1024 grid-gap-10-y grid md:grid-gap-24-y my-24">
      <Block.Text title=weAreTitle> weAreText </Block.Text>
      <Block.Text title=weOfferTitle> weOfferText </Block.Text>
      <Block.Illustration src=illustration />
      <Block.Text title=ourMethodTitle> ourMethodText </Block.Text>
    </main>
    <Block.Section color=`RadicalRed> <Contacts contacts /> </Block.Section>
    <Block.Section color=`Concrete>
      <div> ourMethodText->React.string </div>
    </Block.Section>
  </>;
};

let default = make;
