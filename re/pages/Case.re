module Style = {
  open Css;

  let frameworkImage = style([maxWidth(px(75))]);
};

let narrowContainer = "md:mb-0 mb-0 max-w-3xl grid justify-self-center grid-gap-24-y";

[@react.component]
let make = (~data) => {
  let page = Page.Case.make(data);
  let title = page.contactTitle;

  <>
    <Block.Header
      backgroundImage={page.header.url}
      backgroundFluid={page.header.localFile}
      color={`Other(page.headerBgColor)}
      textColor=`White
      messageOne={page.shortDescription}
    />
    <Container className="md:mb-0 mb-0">
      <Breadcrumbs title={page.title} />
      <div className=narrowContainer>
        <Block.Case
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
                   key=tag className="py-2 px-4 rounded mr-2 mb-2 bg-concrete">
                   {j|$tag|j}->React.string
                 </div>
               )
             ->React.array}
          </div>
        </Block.Case>
        <Block.Case title={`Text(page.introductionTitle)}>
          <p> page.introduction->React.string </p>
        </Block.Case>
        <Block.Case title={`Text(page.processTitle)}>
          <p> page.process->React.string </p>
        </Block.Case>
      </div>
      <Block.Section color=`Concrete>
        <img
          className="justify-self-center"
          width="720"
          src={page.casePageImage.url}
        />
      </Block.Section>
      <div className=narrowContainer>
        <Block.Case title={`Text(page.developmentTitle)}>
          <p> page.development->React.string </p>
        </Block.Case>
      </div>
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
      <div className=narrowContainer>
        <Block.Case title={`Text(page.aboutCompanyTitle)}>
          <p> page.aboutCompany->React.string </p>
        </Block.Case>
      </div>
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
    <Block.Section color=`Aquamarine>
      <Contacts
        layout=`Centered
        contacts={page.contacts}
        ?title
        subtitle={page.contactSubtitle}
      />
    </Block.Section>
  </>;
};
let default = make;
