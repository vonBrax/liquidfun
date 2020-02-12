declare class Vec2 {
  x: number;
  y: number;

  constructor();

  SetZero(): void;

  Set(x: number, y: number): void;

  Length(): number;

  Normalize(): number;

  isValid(): boolean;

  Skew(): Vec2;
}

declare class Vec3 {
  x: number;
  y: number;
  z: number;
}
