module Style = {
  open Css;

  let frameworkImage = style([maxWidth(px(75))]);
};

[@react.component]
let make = (~data) => {
  let page = Page.Case.make(data);

  <>
    <Block.CaseHeader
      backgroundImage={page.header.url}
      backgroundFluid={page.header.localFile}
    />
    <Container className="md:mb-0 mb-0">
      <Breadcrumbs title={page.title} />
      <Block.Element
        title={
                `Image(
                  <img
                    className="max-h-200"
                    src={page.logo}
                    alt={page.title}
                  />,
                )
              }>
        <div className="flex flex-wrap items-center h-full">
          {page.tags
           ->Belt.Array.map(tag =>
               <div
                 key=tag
                 className="h-16 py-2 px-4 rounded mr-2 mb-2 bg-concrete">
                 {j|$tag|j}->React.string
               </div>
             )
           ->React.array}
        </div>
      </Block.Element>
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
      {page.partners
       ->Belt.Option.map(partners =>
           <Block.Element title={`Text(page.partnersTitle)}>
             <Block.Markdown source=partners />
           </Block.Element>
         )
       ->Belt.Option.getWithDefault(React.null)}
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
