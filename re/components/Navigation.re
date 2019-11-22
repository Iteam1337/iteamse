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

    let textColor =
      switch (color) {
      | `White => "text-white"
      | `Black => "text-black"
      };

    <Gatsby.Link
      ariaLabel={j|Gå till $_to|j}
      className={
        Some(
          Css.merge([
            "border-t-4 text-lg font-normal mr-6 last:mr-0 py-8 flex justify-center items-center border-transparent",
            "border-white"->Cn.ifTrue(isActive),
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
let make = (~color=`White) => {
  <div
    className="md:col-start-2 bg-transparent flex flex-1 items-start
    tablet-landscape:px-5">
    <Logo color />
    <nav className="flex ml-auto tablet:hidden">
      {Options.items
       ->Belt.List.map(({link, text}) =>
           <NavigationLink key=link color _to=link text />
         )
       ->Belt.List.toArray
       ->React.array}
    </nav>
  </div>;
};
