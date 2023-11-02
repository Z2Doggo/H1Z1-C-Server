internal void
readPositionUpdateData(App_State *app,
                       Session_State *session,
                       u8 *data,
                       u32 offset)
{
    Zone_Packet_PlayerUpdatePosition obj = {0}; // init
    u32 start_offset = offset;                  // offset is u32 for 2bit values, other than that, will need to typecast to a (u8 *) - doggo

    obj.flag = endian_read_u16_little((u8 *)&offset);
    offset += 2;

    obj.sequence = endian_read_u32_little((u8 *)&offset);
    offset += 4;

    obj.ubyte = endian_read_u8_little((u8 *)&offset);
    offset += 1;

    int2b v;           // signed, also maybe init this aswell?
    euler_angle euler; // needed for the last part of this packet

    if (obj.flag & 1)
    {
        v = endian_read_int2b_little(data, offset);
        session->stance = v.value;
        offset += v.length;
    }

    if (obj.flag & 2)
    {
        v = endian_read_int2b_little(data, offset);
        session->position.x = v.value / 100;
        offset += v.length;
        v = endian_read_int2b_little(data, offset);
        session->position.y = v.value / 100;
        offset += v.length;
        v = endian_read_int2b_little(data, offset);
        session->position.z = v.value / 100;
        offset += v.length;
    }

    if (obj.flag & 0x20)
    {
        session->orientation = endian_read_f32_little((u8 *)&offset);
        offset += 4;
    }

    if (obj.flag & 0x40)
    {
        v = endian_read_int2b_little(data, offset);
        session->front_tilt = v.value / 100;
        offset += v.length;
    }

    if (obj.flag & 0x80)
    {
        v = endian_read_int2b_little(data, offset);
        session->side_tilt = v.value / 100;
        offset += v.length;
    }

    if (obj.flag & 4)
    {
        v = endian_read_int2b_little(data, offset);
        session->angle_change = v.value / 100;
        offset += v.length;
    }

    if (obj.flag & 0x8)
    {
        v = endian_read_int2b_little(data, offset);
        session->vertical_speed = v.value / 100;
        offset += v.length;
    }

    if (obj.flag & 0x10)
    {
        v = endian_read_int2b_little(data, offset);
        session->horizontal_speed = v.value / 10;
        offset += v.length;
    }

    if (obj.flag & 0x100)
    {
        session->unknown12_f32;
        v = endian_read_int2b_little(data, offset);
        session->unknown12_f32.x = v.value / 100;
        offset += v.length;
        v = endian_read_int2b_little(data, offset);
        session->unknown12_f32.y = v.value / 100;
        offset += v.length;
        v = endian_read_int2b_little(data, offset);
        session->unknown12_f32.z = v.value / 100;
        offset += v.length;
    }

    if (obj.flag & 0x200)
    {
        v = endian_read_int2b_little(data, offset);
        euler.qx = v.value / 100;
        offset += v.length;
        v = endian_read_int2b_little(data, offset);
        euler.qy = v.value / 100;
        offset += v.length;
        v = endian_read_int2b_little(data, offset);
        euler.qz = v.value / 100;
        offset += v.length;
        v = endian_read_int2b_little(data, offset);
        euler.qw = v.value / 100;
        session->rotation = eul2quat(&euler);
        session->rotationRaw = euler;
        session->lookAt = eul2quat(&euler); // praying to the machine gods this works
        offset += v.length;
    }

    if (obj.flag & 0x400)
    {
        v = endian_read_int2b_little(data, offset);
        session->direction = v.value / 10;
        offset += v.length;
    }

    if (obj.flag & 0x800)
    {
        v = endian_read_int2b_little(data, offset);
        session->engine_rpm = v.value / 10;
        offset += v.length;
    }

    zone_packet_send(app,
                     session,
                     &app->arena_per_tick,
                     KB(10),
                     Zone_Packet_Kind_PlayerUpdatePosition,
                     &obj);
}