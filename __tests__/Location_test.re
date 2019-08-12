open Jest;
open Expect;
open Location;

describe("#fromString", () => {
  test("handles Stockholm", () =>
    expect(fromString("Stockholm")) |> toEqual(`Stockholm)
  );

  test("handles Gothenburg", () =>
    expect(fromString("Anything")) |> toEqual(`Gothenburg)
  );
});

describe("#toString", () => {
  test("handles all", () =>
    expect(toString(`All)) |> toEqual("Alla")
  );

  test("handles Stockholm", () =>
    expect(toString(`Stockholm)) |> toEqual("Stockholm")
  );

  test("handles Gothenburg", () =>
    expect(toString(`Gothenburg)) |> toEqual({js|Göteborg|js})
  );
});
