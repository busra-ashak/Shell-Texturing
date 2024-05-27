#version 450 core
layout(location = 0) flat in uint plane_id;
layout(location = 1) in vec3 position;
layout(location = 2) in vec4 pos_camera_space;
layout(location = 3) in vec4 normal;

float rand(vec2 n) 
{ 
	return fract(sin(dot(n, vec2(12.9898, 4.1414))) * 43758.5453);
}

void main()
{
    float grass_blade_size_pixels = 192.0;
    vec2 quantized_uv = floor(position.xy * grass_blade_size_pixels ) / grass_blade_size_pixels;
    float noisePerFragment = rand(quantized_uv);
    const float ambient = 0.4f;
    vec3 grass_colour;

    if(noisePerFragment<0.10 + 0.05*plane_id)
    {
        if(plane_id == 0)
        {            
            grass_colour = vec3(0.3,0.4,0.2);
        }
        else
        {
            discard;
        }
    }
    else
    {
        grass_colour = vec3(0.2,0.25 + 0.05*plane_id,0.2);
    }

    vec3 norm = normal.xyz;
    vec3 lightDirection = vec3(0, -1,-0.2);
    vec3 lightColour = vec3(1,1,1);

    float specularStrength = 0.5;
    vec3 viewDirection = normalize(vec3(0,0,0) - pos_camera_space.xyz);
    vec3 reflectDirection = reflect(-lightDirection, norm);
    float spec = pow(max(dot(viewDirection, reflectDirection), 0.0), 8);
    vec3 specular = specularStrength * spec * lightColour;

    vec3 result = (ambient + specular) * grass_colour;
    gl_FragColor = vec4(result, 1.0);
}