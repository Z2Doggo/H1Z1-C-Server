typedef struct playerUpdatePosData playerUpdatePosData;
struct playerUpdatePosData {
	i32 stance;
	i32 position[3];
	i32 unknown_f32[3];
	i32 rotation[4];
	i32 rotationRaw[4];
	i32 lookAt[4];
	f32 orientation;
	i32 direction;
	i32 front_tilt;
	i32 side_tilt;
	i32 angle_change;
	i32 vertical_speed;
	i32 horizontal_speed;
	i32 engine_rpm;
};