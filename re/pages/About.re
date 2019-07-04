[@react.component]
let make = (~data, ~illustrationFun) => {
  let page = Page.About.make(data);

  <>
    <Gatsby.Link _to="/"> "Start"->React.string </Gatsby.Link>
    <main
      className="grid-columns-1fr md:grid-columns-1024 grid-gap-10-y grid md:grid-gap-24-y my-24">
      <Block.Text title={page.valueTitle}> {page.valueText} </Block.Text>
      <Block.Text title={page.funTitle}> {page.funText} </Block.Text>
      <Block.Illustration src=illustrationFun />
      <Block.Text title={page.goodTitle}> {page.goodText} </Block.Text>
      <Block.Image src={page.imageBleed} />
      <Block.Text title={page.stabilityTitle}>
        {page.stabilityText}
      </Block.Text>
      <Block.Text title={page.valueeText}> {page.valueIteam} </Block.Text>
      <Block.Section color=`Aquamarine>
        <Contacts contacts={page.contacts} />
      </Block.Section>
    </main>
  </>;
};

let default = make;
