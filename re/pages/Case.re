module Style = {
  open Css;

  let frameworkImage = style([maxWidth(px(75))]);
};

[@react.component]
let make = (~data) => {
  let page = Page.Case.make(data);

  <>
    <Container className="md:mb-0 mb-0">
      <Breadcrumbs title={page.title} />
      <Block.Text title={page.introductionTitle}>
        {page.introduction}
      </Block.Text>
      <Block.Text title={page.processTitle}> {page.process} </Block.Text>
      <Block.Text title={page.developmentTitle}>
        {page.development}
      </Block.Text>
      {page.quote
       ->Belt.Option.map(quote =>
           <Block.Section
             color={
               page.quoteBgColor
               ->Belt.Option.map(Theme.Colors.fromHex)
               ->Belt.Option.getWithDefault(`CornflowerBlue)
             }>
             <blockquote className="grid grid-gap-8-x col-start-2 col-end-2">
               <p className="text-4xl">
                 {React.string({j|“$quote”|j})}
               </p>
               {page.quotePerson
                ->Belt.Option.map(person =>
                    <footer className="mt-4 text-lg">
                      {React.string({j|— $person|j})}
                    </footer>
                  )
                ->Belt.Option.getWithDefault(React.null)}
             </blockquote>
           </Block.Section>
         )
       ->Belt.Option.getWithDefault(React.null)}
      <Block.Text title={page.aboutCompanyTitle}>
        {page.aboutCompany}
      </Block.Text>
      <Block.Element title={page.partnersTitle}>
        <Block.Markdown source={page.partners} />
      </Block.Element>
      <Block.Section color=`Concrete>
        <div className="grid grid-gap-8-x col-start-2 col-end-2">
          <div>
            <div className="mb-4">
              <Typography.H3> {page.frameworksTitle} </Typography.H3>
            </div>
            <div className="flex flex-wrap justify-center items-center">
              {page.frameworks
               ->Belt.List.fromArray
               ->Belt.List.map(framework =>
                   <div
                     key=framework
                     className="flex flex-col items-center justify-center">
                     <img
                       className={Css.merge(["m-8", Style.frameworkImage])}
                       src={framework |> String.lowercase |> Framework.toImage}
                       alt=framework
                     />
                     framework->React.string
                   </div>
                 )
               ->Belt.List.toArray
               ->React.array}
            </div>
          </div>
        </div>
      </Block.Section>
    </Container>
  </>;
};
let default = make;
