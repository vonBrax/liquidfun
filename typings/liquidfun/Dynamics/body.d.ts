/* eslint-disable @typescript-eslint/triple-slash-reference */
/// <reference path="./Common/math.d.ts" />

declare enum BodyType {
  static = 0,
  kinematic,
  dynamic,
}

declare class BodyDef {
  type: BodyType;
  position: Vec2;
  position3: Vec3;
  angle: number;
  constructor();
}
