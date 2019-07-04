[@react.component]
let make = (~data, ~illustrationGroup, ~illustrationCrane) => {
  let {
    ourMethodTitle,
    ourMethodText,
    weAreText,
    weAreTitle,
    weOfferText,
    weOfferTitle,
    contacts,
    ctaTitle,
    ctaText,
    ctaButton,
  }: Page.Start.t =
    Page.Start.make(data);

  <>
    <Gatsby.Link _to="/om-oss"> "Om oss"->React.string </Gatsby.Link>
    <main
      className="grid-columns-1fr md:grid-columns-1024 grid-gap-10-y grid md:grid-gap-24-y my-24">
      <Block.Text title=weAreTitle> weAreText </Block.Text>
      <Block.Text title=weOfferTitle> weOfferText </Block.Text>
      <Block.Illustration src=illustrationGroup />
      <Block.Text title=ourMethodTitle> ourMethodText </Block.Text>
    </main>
    <Block.Section color=`Concrete>
      <Block.CTA
        illustration=illustrationCrane button=ctaButton title=ctaTitle>
        ctaText
      </Block.CTA>
    </Block.Section>
    <Block.Section color=`RadicalRed> <Contacts contacts /> </Block.Section>
    <Block.Section color=`Concrete>
      <div> ourMethodText->React.string </div>
    </Block.Section>
  </>;
};

let default = make;
