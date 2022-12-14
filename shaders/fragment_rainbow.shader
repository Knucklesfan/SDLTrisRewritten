#version 330 core
out vec4 FragColor;

in vec3 ourColor;
in vec2 TexCoord;

// texture sampler
uniform sampler2D texture1;
uniform vec2 resolution;

uniform float fade;

float NOISE_GRANULARITY = fade/255.0f;

float random(highp vec2 coords) {
   return fract(sin(dot(coords.xy, vec2(12.9898,78.233))) * 43758.5453);
}

void main() {
    
    vec4 fragmentColor = texture(texture1, TexCoord);

    fragmentColor += mix(-NOISE_GRANULARITY, NOISE_GRANULARITY, random(TexCoord));
    gl_FragColor = vec4(vec3(fragmentColor), 1-(fade/512));
}
