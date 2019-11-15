/**
 * Uses custom markdown and styling to
 * get more freedom in styling the blog
 */
module Style = {
  open Css;

  let container =
    merge([
      "grid my-10 my-8 md:my-24",
      style([
        gridTemplateColumns([
          `px(20),
          `fr(1.0),
          `px(32),
          `minmax((`px(300), `px(984))),
          `px(32),
          `fr(1.0),
          `px(20),
        ]),
        selector(
          "> *",
          [
            gridColumn(3, 6),
            media("(min-width: 769px)", [gridColumn(4, 5)]),
          ],
        ),
        selector(
          "figure",
          [
            gridColumn(-1, 1),
            marginTop(`rem(1.25)),
            marginBottom(`px(48)),
            media("(min-width: 769px)", [gridColumn(3, 6)]),
          ],
        ),
        selector(
          "figcaption",
          [
            color(`hex("4A5568")),
            fontSize(`rem(0.875)),
            textAlign(`center),
            marginLeft(`auto),
            marginRight(`auto),
            maxWidth(`percent(75.0)),
            marginTop(`rem(0.75)),
          ],
        ),
        selector(
          "ul",
          [paddingLeft(`rem(1.25)), marginBottom(`rem(2.0))],
        ),
        selector("li", [fontSize(`rem(1.125))]),
        selector(
          "h2",
          [
            fontSize(`rem(1.5)),
            fontWeight(`medium),
            paddingBottom(`rem(1.0)),
          ],
        ),
        // YouTube videos - aspect ratio trick
        selector(
          ".kg-embed-card",
          [
            paddingTop(`percent(56.25)),
            position(`relative),
            width(`percent(100.0)),
          ],
        ),
        selector(
          ".kg-embed-card iframe",
          [
            height(`percent(100.0)),
            left(`px(0)),
            position(`absolute),
            top(`px(0)),
            width(`percent(100.0)),
          ],
        ),
      ]),
    ]);
};

[@react.component]
let make = (~data) => {
  let page = Page.Blog.make(data);

  <>
    <Block.Header
      backgroundImage={page.featureImage}
      color=`Aquamarine
      messageOne={page.title}
    />
    <div className=Style.container>
      <Breadcrumbs title={page.title} />
      <div className="text-gray-600 mt-10 mb-5 flex items-center">
        {React.string(page.publishedAt)}
        {switch (page.tag) {
         | Some(tag) =>
           <>
             <div className="px-2"> {React.string("/")} </div>
             <div> {React.string(tag.name)} </div>
           </>
         | None => React.null
         }}
      </div>
      Block.Markdown.(
        page.content
        |> Js.String.replaceByRe([%re "/\\n\\s+/g"], "")
        |> Dedent.make
        |> Generate.make
        |> Parse.make
      )
      <div className="mt-12">
        <div className="flex items-center">
          <img
            className="rounded-full w-16 h-16 object-cover"
            src={page.author.profileImage}
          />
          <div className="flex flex-col ml-5">
            <h3 className="text-lg font-medium">
              {React.string(page.author.name)}
            </h3>
            {switch (page.author.bio) {
             | Some(bio) =>
               <div className="text-gray-600"> {React.string(bio)} </div>
             | None => React.null
             }}
          </div>
        </div>
      </div>
    </div>
  </>;
};
