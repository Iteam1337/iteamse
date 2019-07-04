[@react.component]
let make = (~data, ~illustrationGroup, ~illustrationCrane) => {
  let page = Page.Start.make(data);

  <>
    <div
      className="grid grid-columns-1fr md:grid-columns-1024 grid-gap-10-y
      md:grid-gap-24-y my-24">
      <div className="col-start-2">
        <Gatsby.Link className=None _to="/om-oss">
          "Om oss"->React.string
        </Gatsby.Link>
        <Gatsby.Link className=None _to="/medarbetare">
          "Medarbetare"->React.string
        </Gatsby.Link>
        <Gatsby.Link className=None _to="/hur-vi-jobbar">
          "Hur vi jobbar"->React.string
        </Gatsby.Link>
      </div>
      <Block.Text title={page.weAreTitle}> {page.weAreText} </Block.Text>
      <Block.Text title={page.weOfferTitle}> {page.weOfferText} </Block.Text>
      <Block.Illustration src=illustrationGroup />
      <Block.Text title={page.ourMethodTitle}>
        {page.ourMethodText}
      </Block.Text>
    </div>
    <Block.Section color=`Concrete>
      <Block.CTA
        illustration=illustrationCrane
        button={page.ctaButton}
        title={page.ctaTitle}>
        {page.ctaText}
      </Block.CTA>
    </Block.Section>
    <Block.Section color=`RadicalRed>
      <Contacts contacts={page.contacts} />
    </Block.Section>
  </>;
};

let default = make;
