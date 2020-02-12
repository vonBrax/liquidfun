/* eslint-disable @typescript-eslint/triple-slash-reference */
/* eslint-disable @typescript-eslint/camelcase */

/// <reference path="../Common/math.d.ts" />
/// <reference path="../body.d.ts" />

declare enum JointType {
  unknownJoint,
  revoluteJoint,
  prismaticJoint,
  distanceJoint,
  pulleyJoint,
  mouseJoint,
  gearJoint,
  wheelJoint,
  weldJoint,
  frictionJoint,
  ropeJoint,
  motorJoint,
}

declare enum LimitState {
  inactiveLimit,
  atLowerLimit,
  atUpperLimit,
  equalLimits,
}

declare interface Jacobian {
  linear: Vec2;
  angularA: number;
  angularB: number;
}

/// A joint edge is used to connect bodies and joints together
/// in a joint graph where each body is a node and each joint
/// is an edge. A joint edge belongs to a doubly linked list
/// maintained in each attached body. Each joint has two joint
/// nodes, one for each attached body.
declare interface JointEdge {
  other: Body; ///< provides quick access to the other body attached.
  joint: Joint; ///< the joint
  prev: JointEdge; ///< the previous joint edge in the body's joint list
  next: JointEdge; ///< the next joint edge in the body's joint list
}

/// Joint definitions are used to construct joints.
declare class JointDef {
  constructor();

  /// The joint type is set automatically for concrete joint types.
  type: JointType;

  /// Use this to attach application specific data to your joints.
  userData: void;

  /// The first attached body.
  bodyA: Body;

  /// The second attached body.
  bodyB: Body;

  /// Set this flag to true if the attached bodies should collide.
  collideConnected: boolean;
}

/// The base joint class. Joints are used to constraint two bodies together in
/// various fashions. Some joints also feature limits and motors.
declare class Joint {
  protected type: JointType;
  protected prev: Joint;
  protected next: Joint;
  protected edgeA: JointEdge;
  protected edgeB: JointEdge;
  protected bodyA: Body;
  protected bodyB: Body;

  protected index: number;

  protected islandFlag: boolean;
  protected collideConnected: boolean;

  protected userData: void;

  protected constructor(def: JointDef);
  /// Get the type of the concrete joint.
  GetType(): JointType;

  /// Get the first body attached to this joint.
  GetBodyA(): Body;

  /// Get the second body attached to this joint.
  GetBodyB(): Body;

  /// Get the anchor point on bodyA in world coordinates.
  GetAnchorA(): Vec2;

  /// Get the anchor point on bodyB in world coordinates.
  GetAnchorB(): Vec2;

  /// Get the reaction force on bodyB at the joint anchor in Newtons.
  GetReactionForce(inv_dt: number): Vec2;

  /// Get the reaction torque on bodyB in N*m.
  GetReactionTorque(inv_dt: number): number;

  /// Get the next joint the world joint list.
  GetNext(): Joint;

  /// Get the user data pointer.
  GetUserData(): void;

  /// Set the user data pointer.
  SetUserData(data: void): void;

  /// Short-cut function to determine if either body is inactive.
  IsActive(): boolean;

  /// Get collide connected.
  /// Note: modifying the collide connect flag won't work correctly because
  /// the flag is only checked when fixture AABBs begin to overlap.
  GetCollideConnected(): boolean;

  /// Dump this joint to the log file.
  Dump(): void;

  /// Shift the origin for any points stored in world coordinates.
  ShiftOrigin(newOrigin: Vec2): void;

  protected static Create(def: JointDef, allocator: BlockAllocator): Joint;
  protected static Destroy(joint: Joint, allocator: BlockAllocator): void;

  protected InitVelocityConstraints(data: SolverData): void;
  protected SolveVelocityConstraints(data: SolverData): void;

  // This returns true if the position errors are within tolerance.
  protected SolvePositionConstraints(data: SolverData): boolean;
}
