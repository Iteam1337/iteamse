[@react.component]
let make = (~data) => {
  let page = Page.Blog.make(data);

  <Container>
    {page
     ->Belt.List.map(item =>
         <div key={item.slug}>
           <Typography.H2> {item.title} </Typography.H2>
           <Block.Markdown source={item.content} />
         </div>
       )
     ->Belt.List.toArray
     ->React.array}
  </Container>;
};

let default = make;
