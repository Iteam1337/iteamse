[@react.component]
let make = (~data, ~illustrationFun) => {
  let page = Page.About.make(data);

  <>
    <Gatsby.Link className=None _to="/"> "Start"->React.string </Gatsby.Link>
    <Block.Header
      backgroundImage={page.header.url}
      color={page.header.textBgColor}
      messageOne={page.header.text}
      messageTwo={page.header.textSecond}
    />
    <div
      className="grid-columns-1fr md:grid-columns-1024 grid-gap-10-y grid md:grid-gap-24-y my-24">
      <Block.Text title={page.valueTitle}> {page.valueText} </Block.Text>
      <Block.Text title={page.funTitle}> {page.funText} </Block.Text>
      <Block.Illustration src=illustrationFun />
      <Block.Text title={page.goodTitle}> {page.goodText} </Block.Text>
      <Block.Image src={page.imageBleed} />
      <Block.Element title={page.stabilityTitle}>
        page.stabilityText->React.string
        <div className="mt-10 flex items-center">
          {page.stabilityIcons
           ->Belt.List.map(src =>
               <img key=src className="mr-5 w-40" src alt="" />
             )
           ->Belt.List.toArray
           ->React.array}
        </div>
      </Block.Element>
      <Block.Text title={page.valueeText}> {page.valueIteam} </Block.Text>
    </div>
    <Block.Section color=`Aquamarine>
      <Contacts contacts={page.contacts} title={page.contactTitle} />
    </Block.Section>
  </>;
};

let default = make;
