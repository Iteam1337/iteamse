module NavigationLink = {
  [@react.component]
  let make = (~_to, ~text, ~color) => {
    let (_urlParts, setUrlParts) = React.useState(() => None);
    let (isActive, setIsActive) = React.useState(() => false);

    React.useEffect0(() => {
      let parts =
        Js.String.split("/", Breadcrumbs.JsWindow.location)
        ->Belt.List.fromArray
        ->Belt.List.tail
        ->Belt.Option.getWithDefault([])
        ->Belt.List.head
        ->Belt.Option.getWithDefault("/");

      let isActive = "/" ++ parts == _to;

      setUrlParts(_prevParts => Some(parts));
      setIsActive(_wasActive => isActive);

      None;
    });

    let (textColor, borderColor) =
      switch (color) {
      | `White => ("text-white", "border-white")
      | `Black => ("text-black", "border-black")
      };

    <Gatsby.Link
      ariaLabel={j|Gå till $_to|j}
      className={
        Some(
          Css.merge([
            "border-t-4 text-lg font-normal mr-6 last:mr-0 py-8 flex justify-center items-center border-transparent",
            borderColor->Cn.ifTrue(isActive),
            textColor,
          ]),
        )
      }
      _to>
      text->React.string
    </Gatsby.Link>;
  };
};

module Options = {
  type t = {
    link: string,
    text: string,
  };

  let items = [
    {link: "/erbjudanden", text: "Erbjudanden"},
    {link: "/case", text: {j|Våra case|j}},
    {link: "/hur-vi-jobbar", text: "Metod"},
    {link: "/medarbetare", text: "Medarbetare"},
    {link: "/karriar", text: {j|Karriär|j}},
    {link: "/om-oss", text: "Om oss"},
    {link: "/labs", text: "Labs"},
  ];
};

[@react.component]
let make = (~color=`White, ~navStyle=`Default) => {
  let bg =
    switch (color, navStyle) {
    | (`White, _) => "md:bg-transparent"
    | (`Black, `Case) => "md:bg-white"
    | (`Black, _) => "md:bg-transparent"
    };

  let className =
    Css.merge([
      "flex flex-1 md:grid items-start tablet-landscape:px-5 col-bleed md:grid-columns-1024 grid-columns-1fr",
      bg,
    ]);

  <div className>
    <div className="md:col-start-3 flex items-center">
      {switch (navStyle) {
       | `Case =>
         <>
           <div className="md:hidden py-8"> <Logo color=`White /> </div>
           <div className="hidden md:block py-8"> <Logo color /> </div>
         </>
       | _ => <div className="py-8"> <Logo color /> </div>
       }}
      <nav className="flex ml-auto tablet:hidden">
        {Options.items
         ->Belt.List.map(({link, text}) =>
             <NavigationLink key=link color _to=link text />
           )
         ->Belt.List.toArray
         ->React.array}
      </nav>
    </div>
  </div>;
};
