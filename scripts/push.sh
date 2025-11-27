#!/bin/bash

if [[ -z DOCKER_IMG ]]; then
    export DOCKER_IMG=colbr:latest
    echo "DOCKER_IMG env var not set, using default: ${DOCKER_IMG}"
fi

echo "Creating temp container temp_colbr..."
docker run -d --name temp_colbr ${DOCKER_IMG} sleep infinity
echo "Copying script to conatiner..."
docker cp ./mapreduce-sim.cc temp_colbr:/app/ns-3-dev/scratch/mapreduce-sim.cc
echo "Commiting changes to image ${DOCKER_IMG}..."
docker commit temp_colbr ${DOCKER_IMG}
echo "Cleaning up temp container..."
docker stop temp_colbr > /dev/null 2>&1
docker rm temp_colbr > /dev/null 2>&1