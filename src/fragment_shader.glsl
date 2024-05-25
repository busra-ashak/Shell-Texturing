#version 450 core
layout(location = 0) flat in uint plane_id;
layout(location = 1) in vec3 position;

float rand(vec2 n) 
{ 
	return fract(sin(dot(n, vec2(12.9898, 4.1414))) * 43758.5453);
}

void main()
{
    //gl_FragColor = vec4(0.2*plane_id, 0.6, 0.2, 1.0);
    float grass_blade_size_pixels = 128.0;
    vec2 quantized_uv = floor(position.xy * grass_blade_size_pixels ) / grass_blade_size_pixels;
    float noisePerFragment = rand(quantized_uv);
    if(noisePerFragment<0.2 + 0.1*plane_id)
    {
        if(plane_id == 0)
        {
            gl_FragColor = vec4(0.3,0.4,0.2, 1.0);
        }
        else
        {
            discard;
        }
    }
    else
    {
        gl_FragColor = vec4(0.2,0.5 + 0.05*plane_id,0.2, 1.0);
    }
}