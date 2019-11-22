module Style = {
  open Css;

  let grid =
    merge([
      "grid",
      style([
        gridTemplateColumns([`px(300), `fr(1.0)]),
        media(
          Theme.Breakpoints.fromType(`Mobile),
          [gridTemplateColumns([`fr(1.0)])],
        ),
      ]),
    ]);
};

[@react.component]
let make = (~posts, ~settings) => {
  let page = Page.Blog.Short.make(~posts, ~settings);

  <>
    <Block.Header
      backgroundImage={page.settings.cover}
      color=`RadicalRed
      messageOne="Labs"
    />
    <Container>
      {page.posts
       ->Belt.List.map(item => {
           let postTitle = item.title;

           <Gatsby.Link
             ariaLabel={j|Gå till blogg-inlägget: $postTitle|j}
             className={Some(Style.grid)}
             key={item.slug}
             _to={"/labs/" ++ item.slug}>
             <div>
               <img
                 className="w-full h-48 object-cover rounded"
                 src={item.featureImage}
               />
             </div>
             <article className="ml-1 mt-4 md:ml-10 md:mt-0">
               <header className="mb-2">
                 <h2 className="text-lg font-semibold mb-4">
                   {React.string(item.title)}
                 </h2>
               </header>
               <div className="text-gray-800">
                 {React.string(item.content)}
               </div>
               <div className="flex items-center mt-4">
                 <div>
                   <img
                     alt={item.author.name}
                     className="w-6 h-6 rounded-full object-cover"
                     src={item.author.profileImage}
                   />
                 </div>
                 <div className="text-xs px-2 text-gray-700">
                   {React.string("/")}
                 </div>
                 <div className="text-xs text-gray-700">
                   {React.string(item.publishedAt)}
                 </div>
               </div>
             </article>
           </Gatsby.Link>;
         })
       ->Belt.List.toArray
       ->React.array}
    </Container>
  </>;
};

let default = make;
