[@react.component]
let make = (~data, ~illustrationFun, ~numberOfEmployees) => {
  let page = Page.About.make(data);

  <>
    <Block.Header
      backgroundImage={page.header.url}
      backgroundFluid={page.header.localFile}
      color={page.header.textBgColor}
      messageOne={page.header.text}
      messageTwo={page.header.textSecond}
    />
    <Container>
      <Block.Text title={page.valueeText}>
        {page.valueIteam
         |> Js.String.replace(
              "{{coworkers}}",
              numberOfEmployees->string_of_int,
            )}
      </Block.Text>
      <Block.Text title={page.valueTitle}> {page.valueText} </Block.Text>
      <Block.Text title={page.funTitle}> {page.funText} </Block.Text>
      <Block.Illustration src=illustrationFun />
      <Block.Text title={page.goodTitle}> {page.goodText} </Block.Text>
      <Gatsby.FluidImg
        className={Some("col-bleed w-full")}
        fluid=data##imageBleed##fluid
      />
      <Block.Element title={page.stabilityTitle}>
        page.stabilityText->React.string
        <div className="mt-10 flex items-center flex-wrap justify-center">
          {page.stabilityIcons
           ->Belt.List.map(((alt, src)) =>
               <img key=src className="md:mr-5 mx-5 my-5 w-40" src alt />
             )
           ->Belt.List.toArray
           ->React.array}
        </div>
      </Block.Element>
    </Container>
    <Block.Section color=`Aquamarine>
      <Contacts contacts={page.contacts} title={page.contactTitle} />
    </Block.Section>
  </>;
};

let default = make;
